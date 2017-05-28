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
var name = new Map([[1,'Charlotte'], [2,'Cherry'], [3,'Vivian'], [4,'Patricia'],
		[5,'Marjory'], [6,'Francoise'], [7,'Kalypso'], [8,'Sofie'],
		[9,'plantation-choux'], [10,'lounge']]),
	pos = new Map([[1, {x:0, y:2}], [2, {x:3, y:2}], [3, {x:2, y:4}], [4, {x:4, y:5}],
		[5, {x:4, y:12}], [6, {x:12, y:3}], [7, {x:5, y:8}], [8, {x:8, y:6}]]),
	schedule = new Map([[1, []]]);

// === Jobs ===
function	runJobs() {
	jobs.forEach(function(job) { job(); });
}
function	wrapJob(j, arg) {
	return function() { j(arg); };
}
function	walk(ID) {
	var tmp = pos.get(ID),
		nxt = { x: tmp.x + Math.round(Math.random()*2-1),
		y: tmp.y + Math.round(Math.random()*2-1) };
	pos.set(ID, { x: nxt.x<=0? 0: nxt.x>=MAXX? MAXX-1: nxt.x,
			y: nxt.y<=0? 0: nxt.y>=MAXY? MAXY-1: nxt.y });
}
var jobs = new Set([wrapJob(walk, 1), wrapJob(walk, 2), wrapJob(walk, 3), wrapJob(walk, 4),
	wrapJob(walk, 5), wrapJob(walk, 6), wrapJob(walk, 7), wrapJob(walk, 8)]);

// === Event handler ===
/*window.addEventListener('keydown', function(event) {
  switch (event.keyCode) {
	// --- LEFT ---
    case 37: // Left
    case 65: // a
	case 72: // h
		Left();
    break;
	// --- RIGHT ---
    case 39: // Right
    case 68: // d
	case 76: // l
		Right();
    break;
	// --- UP ---
    case 38: // Up
    case 87: // w
	case 75: // k
		Up();
    break;
	// --- DOWN ---
    case 40: // Down
    case 83: // s
	case 74: // j
		Down();
    break;
	// --- A ---
	case 96:  // numpad 0
	case 188: // ,
	case 13:  // enter
		A();
	break;
	// --- B ---
	case 110: // numpad .
	case 190: // period .
	case 27:  // escape
		B();
	break;
  }
  cursor.context.setPosition();
}, false);*/

// --- METHODS ---
// === !Event handler ===

// === drawing ===
//var BGimg = new Image();
//BGimg.src = "BG.png";
/*var drawBG = function(){
	try {
		ctx.drawImage(BGimg, 0, 0, 320, 288, 0, 0, 320, 288);
	} catch (e) {}
}*/
function toGrid(pos) {
	return {x:pos.x*width*.01+width*.2+width*.1/MAXY*(MAXY-pos.y), y:pos.y*height*.01+height*.3};
}
function drawChars() {
	ctx.beginPath();
	let tmp = {x:0, y:0};
	pos.forEach(function(pos, ID) {
		tmp = toGrid(pos);
		ctx.moveTo(tmp.x, tmp.y);
		ctx.lineTo(tmp.x+width*.01, tmp.y);
		ctx.lineTo(tmp.x+width*.008, tmp.y+height*.01);
		ctx.lineTo(tmp.x-width*.002, tmp.y+height*.01);
		ctx.lineTo(tmp.x, tmp.y);
	});
	ctx.strokeStyle = 'magenta';
	ctx.stroke();
	ctx.closePath();
}
function drawShop() {
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
	drawChars();
	drawShop();
		//gui
	drawGameClock();

	gLoop = setTimeout(GameLoop, 1000/1.65);
}
GameLoop();
// ==========
