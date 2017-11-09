<?php 
 	header("Content-Type: text/html;charset=utf-8");
	require("inc.php");

	$name=$_POST['name'];
	$address=$_POST['address'];
	$telephone=$_POST['telephone'];
	$qq=$_POST[qq'];
	$introduce=$_POST['introduce'];
	$weixin=$_POST['weixin'];
	$email=$_POST['email'];
	$sql="insert into student_record(user_name,user_address,user_telephone,user_qq,user_introduce,user_weixin,user_email)
values('$name','$address','$telephone','$qq','$introduce','$weixin','$email')";
	if(!mysql_query($sql,$conn)){
		die('Error: ' . mysql_error());
	}else{
		header("Location: /1/v_supplier.php"); 
	};
	mysql_close($conn);


?>
