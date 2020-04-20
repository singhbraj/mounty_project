const express = require("express");
const port = process.env.PORT || 3000;
const app  = express();

const mysql = require('mysql');
var db   = require('./db');
var addUser= require('./control/addUser');
var deleteUser= require('./control/deleteUser');
var allUser= require('./control/allUser');
var updateUser= require('./control/updateUser');


const bodyParser  = require("body-parser");
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.get('/addUser', addUser);
app.delete('/deleteUser', deleteUser);
app.put('/updateUser', updateUser);
app.get('/findAllUser',allUser);

app.listen(port, function() {
    console.log('Express server listening on port ' +port);
});
