// required when running on node.js
// var mqtt = require('mqtt');

var user = "javascripttest";
var token = "0a5c2e61be56cb42";
var client;

function setup(){
  client = mqtt.connect('mqtt://'+ user + ':' + token + '@broker.shiftr.io', {
    clientId: 'javascript'
  });

  client.on('connect', function(){
    console.log('client has connected!');
  });

  client.on('message', function(topic, message) {
    console.log('new message:', topic, message.toString());
    if(message.toString() == 'the mouse is out'){
      client.publish('message/receiced', 'too late to set the trap');
    }
  });
  client.subscribe('/+/mouse');
  // client.unsubscribe('/example');
}

function draw(){
  background(255,0,0);
}

function mouseClicked(){
  client.publish('/hello/mouse', 'the mouse is out');
}
