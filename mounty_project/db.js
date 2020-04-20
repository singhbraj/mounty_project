const mysql      = require('mysql');
const connection = mysql.createConnection({
    host     : 'localhost',
    user     : 'Braj',
    password : '123',
    database : 'mydb'
});

connection.connect(function(err) {
  if (err) {
   
    console.log('Not found!');
  }
   else
  console.log('connected as id ' + connection.threadId);
});
module.exports=connection;