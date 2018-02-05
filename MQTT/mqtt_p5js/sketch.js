// required when running on node.js
// var mqtt = require('mqtt');
function setup(){

}

function draw(){
  background(255,0,0);
  ellipse(56, 46, 55, 55);
}

function mouseClicked(){
  var client = mqtt.connect('mqtt://try:try@broker.shiftr.io', {
    clientId: 'javascript'
  });

  client.on('connect', function(){
    console.log('client has connected!');

    client.subscribe('/example');
    // client.unsubscribe('/example');

    setInterval(function(){
      client.publish('/hello', 'katte');
    }, 500);
  });

  client.on('message', function(topic, message) {
    console.log('new message:', topic, message.toString());
  });

}
