var canvas = document.getElementById("starfield");

var w = 1200;
var h = 600;

canvas.setAttribute("width", w);
canvas.setAttribute("height", h);

var c = canvas.getContext("2d");

rand = function () { return (Math.random() - 0.5) * (Math.random() - 0.5) * Math.random() };

var cx = w / 2;
var cy = h / 2;

var count = 170;
var stars = [];
for (var i = 0; i < count; i++) {
    var sx = cx + rand() * w;
    var sy = cy + rand() * h;
    var s = [sx, sy];
    stars.push(s);
}

// main loop
var fps = 50;
setInterval(function () {
    c.clearRect(0, 0, w, h);

    // iterate over stars
    for (var i = 0; i < stars.length; i++) {
        var x = stars[i][0];
        var y = stars[i][1];

        var r = 0.006 * (Math.sqrt(Math.pow(x - cx, 2) + Math.pow(y - cy, 2)));

        c.beginPath();
        c.arc(x, y, r, 0, 2 * Math.PI, false);
        c.fillStyle = "white";
        c.fill();

        var nx = x + (x - cx) * 0.025;
        var ny = y + (y - cy) * 0.025;
        stars[i] = [nx, ny];

        if (x < -100 || x > w + 100 || y < -100 || y > h + 100) {
            x = cx + rand() * w / 10;
            y = cy + rand() * w / 10;
            stars[i] = [x, y];
        }
    }
}, 1000 / fps);