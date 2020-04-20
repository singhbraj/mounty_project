var mysql   = require("mysql");
var express = require("express");
const connection = mysql.createConnection({
    host     : 'localhost',
    user     : 'Braj',
    password : '123',
    database : 'mydb'
});


 var updateUser = function(req,res, next){
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
        var sql = "UPDATE user SET email = '"+post.email+"',phone = '"+post.phone+"',date = '"+post.date+"',room_no = '"+post.room_no+"',time = '"+post.time+"' WHERE Name = '"+post.Name+"'";
  connection.query(sql, function (err, result) {
   
    if (err) console.log('Something went wrong!');
    else
   res.end('User data updated Succesfully !');
  });
}
  });
    
 }

   module.exports = updateUser;