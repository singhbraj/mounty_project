var mysql   = require("mysql");
var express = require("express");
const connection = mysql.createConnection({
    host     : 'localhost',
    user     : 'Braj',
    password : '123',
    database : 'mydb'
});


 var addUser = function(req,res, next){
   date = new Date();
   var post={
   Name:req.body.Name,
   email:req.body.email,
   phone:req.body.phone,
   date:date,
   room_no:req.body.room_no,
   time:date.getTime()
   }
   console.log(post);
   connection.connect(function(err) {
    if (err) {
     
      console.log('Not found!');
    }
     else{
  var sql = "INSERT INTO user (name,email,phone,date,room_no,time) VALUES ('"+post.Name+"', '"+post.email+"','"+post.phone+"','"+post.date+"','"+post.room_no+"','"+post.time+"')";
  connection.query(sql, function (err, result) {
   
    if (err) console.log('Something went wrong!');
    else
      res.end('User added Succesfully!');
  });
}
  });
    
 }

   module.exports = addUser;