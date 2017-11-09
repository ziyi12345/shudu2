<?php


  $mysql_server_name="localhost:3306"; //数据库服务器名称
  $mysql_username="root"; // 连接数据库用户名
  $mysql_password="123456"; // 连接数据库密码
  $mysql_database="test"; // 数据库的名字
    
    // 连接到数据库
  $conn=mysql_connect($mysql_server_name, $mysql_username,$mysql_password);
  //设置数据的字符集utf-8 
  mysql_query("set names 'utf8' ");
  mysql_query("set character_set_client=utf8");
  mysql_query("set character_set_results=utf8");
  if(!$conn){
    die('Could not connect: ' . mysql_error());
  }
  mysql_select_db($mysql_database,$conn);//选择数据库

?>