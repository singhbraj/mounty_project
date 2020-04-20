var mysql   = require("mysql");
var express = require("express");
const connection = mysql.createConnection({
    host     : 'localhost',
    user     : 'Braj',
    password : '123',
    database : 'mydb'
});

 var allUser = function(req,res, next){
   console.log('Hello');
   connection.connect(function(err) {
    if (err) {
      console.log('Not found!');
    }
     else{
        connection.query("SELECT * FROM user", function (err, result, fields) {
            if(err) console.log('wrong')
            console.log(result);
            res.send(result);
          });
}
  });
    
 }

   module.exports = allUser;