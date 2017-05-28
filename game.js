// LSF game.js version 0.1
// Written by dyarob
// May 2017


// === Global variables for the canvas' attributes ===
var width = (window.innerWidth || root.clientWidth || body.clientWidth) - 2,
	height = (window.innerHeight || root.clientHeight || body.clientHeight) - 2,
  c = document.getElementById('c'), 
  ctx = c.getContext('2d');
c.width = width;	c.height = height;
ctx.translate(0.5, 0.5); //drawing lines exactly 1px wide
ctx.fillStyle = 'white';

// === GLOBALS ===
var MAXX = 50, MAXY = 40,
	gameTime = 8*60000, dt = 0, newDate = lastDate = (new Date()).valueOf();

// === Globals for Components ===
var nam = new Map([[1,'Charlotte'], [2,'Cherry'], [3,'Vivian'], [4,'Patricia'],
		[5,'Marjory'], [6,'Francoise'], [7,'Kalypso'], [8,'Sofie'],
		[9,'plantation-choux'], [10,'lounge']]),
	pos = new Map([[1, {x:0, y:2}], [2, {x:3, y:2}], [3, {x:2, y:4}], [4, {x:4, y:5}],
		[5, {x:4, y:12}], [6, {x:12, y:3}], [7, {x:5, y:8}], [8, {x:8, y:6}]]);



// === Jobs ===
function	job(j, arg) {
	return function() { j(arg); };
}
var jobs = new Set([job(walk, 1), job(walk, 2), job(walk, 3), job(walk, 4),
	job(walk, 5), job(walk, 6), job(walk, 7), job(walk, 8)]);
function	runJobs() {
	jobs.forEach(function(job) { job(); });
}
function	walk(ID) {
	var tmp = pos.get(ID),
		nxt = { x: tmp.x + Math.round(Math.random()*2-1),
		y: tmp.y + Math.round(Math.random()*2-1) };
	pos.set(ID, { x: nxt.x<=0? 0: nxt.x>=MAXX? MAXX-1: nxt.x,
			y: nxt.y<=0? 0: nxt.y>=MAXY? MAXY-1: nxt.y });
}



// === Event handler ===
var	clickMap = new Array();
for (let i = 0; i<~~(height/10); ++i) {
	clickMap[i] = new Array();
	for (let j = 0; j<~~(width/10); ++j) {
		clickMap[i][j] = 0;
	}
}
pos.forEach(function(p, ID) {
		let tmp = toGrid(p);
		clickMap[~~(tmp.x/10)][~~(tmp.y/10)] = ID; });
c.addEventListener('click', function(event) {
		if (clickMap[~~(event.pageX/10)][~~(event.pageY/10)]) {
			//open entity contextual menu
		}
	}, false);
/*window.addEventListener('keydown', function(event) {
  switch (event.keyCode) {
	// --- LEFT ---
    case 37: // Left
    case 65: // a
	case 72: // h
		Left();
    break;
  }
  cursor.context.setPosition();
}, false);*/
// --- METHODS ---
// === !Event handler ===



// === drawing ===
function toGrid(pos) {
	return {x:pos.x*width*.01+width*.2+width*.1/MAXY*(MAXY-pos.y), y:pos.y*height*.01+height*.3};
}
function drawChars() {
	ctx.fillStyle = 'magenta';
	ctx.beginPath();
	let tmp = {x:0, y:0};
	pos.forEach(function(pos, ID) {
		tmp = toGrid(pos);
		ctx.moveTo(tmp.x, tmp.y);
		ctx.lineTo(tmp.x+width*.01, tmp.y);
		ctx.lineTo(tmp.x+width*.008, tmp.y+height*.01);
		ctx.lineTo(tmp.x-width*.002, tmp.y+height*.01);
		ctx.lineTo(tmp.x, tmp.y);
		ctx.fillText(nam.get(ID), tmp.x+width*.010, tmp.y-height*.006, 100);
	});
	ctx.strokeStyle = 'magenta';
	ctx.stroke();
	ctx.closePath();
	ctx.fillStyle = 'white';
}
function drawShop() {
	ctx.fillStyle = 'green';
	ctx.beginPath();
	var tmp = toGrid({x:9, y:4});
	ctx.moveTo(tmp.x, tmp.y);
	ctx.lineTo(tmp.x+width*.08, tmp.y);
	ctx.lineTo(tmp.x+width*.064, tmp.y+height*.08);
	ctx.lineTo(tmp.x-width*.016, tmp.y+height*.08);
	ctx.lineTo(tmp.x, tmp.y);
	ctx.strokeStyle = 'green';
	ctx.stroke();
	ctx.closePath();
	ctx.fillText(nam.get(9), tmp.x, tmp.y-height*.006, 100);
	ctx.beginPath();
	var tmp = toGrid({x:13, y:15});
	ctx.moveTo(tmp.x, tmp.y);
	ctx.lineTo(tmp.x+width*.08, tmp.y);
	ctx.lineTo(tmp.x+width*.064, tmp.y+height*.08);
	ctx.lineTo(tmp.x-width*.016, tmp.y+height*.08);
	ctx.lineTo(tmp.x, tmp.y);
	ctx.strokeStyle = 'green';
	ctx.stroke();
	ctx.closePath();
	ctx.fillText(nam.get(10), tmp.x, tmp.y-height*.006, 100);
	ctx.fillStyle = 'white';
}
function	drawGameClock() {
	ctx.fillText(~~(gameTime/60000) +" O'Clock", width/2-50, 20, 100);
}
// ==========



// === Main loop ===
var GameLoop = function(){
	// processing
		//clock
	lastDate = newDate;
	newDate = (new Date()).valueOf();
	dt = newDate - lastDate;
	gameTime = (gameTime + dt) % (24*60000);
		//others
	runJobs();

	// drawing
		//scenery
	ctx.clearRect(0, 0, c.width, c.height);
	ctx.beginPath();
	ctx.moveTo(width*.3, height*.3);
	ctx.lineTo(width*.8, height*.3);
	ctx.lineTo(width*.7, height*.7);
	ctx.lineTo(width*.2, height*.7);
	ctx.lineTo(width*.3, height*.3);
	ctx.strokeStyle = 'white';
	ctx.stroke();
	ctx.closePath();
		//overlay
	drawShop();
	drawChars();
		//gui
	drawGameClock();

	gLoop = setTimeout(GameLoop, 1000/1.65);
}
GameLoop();
// ==========
