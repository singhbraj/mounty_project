var mysql   = require("mysql");
var express = require("express");
const connection = mysql.createConnection({
    host     : 'localhost',
    user     : 'Braj',
    password : '123',
    database : 'mydb'
});

 var deleteUser = function(req,res, next){
   var post={
   Name:req.body.Name,
   room_no:req.body.room_no,
   }
   console.log(post);
   connection.connect(function(err) {
    if (err) {
     
      console.log('Not found!');
    }
     else{
        var sql = "DELETE FROM user WHERE Name = '"+post.Name+"' AND room_no = '"+post.room_no+"' ";
  connection.query(sql, function (err, result) {
   
    if (err) console.log('Something went wrong!');
    else
      res.end('User Deleted Succesfully!');
  });
}
  });
    
 }

   module.exports = deleteUser;