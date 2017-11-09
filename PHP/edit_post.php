<?php 
 	header("Content-Type: text/html;charset=utf-8");
	require("inc.php");

	$name=$_POST['user_name'];
	$tel=$_POST['tel'];
	$add=$_POST['address'];
	$qq=$_POST['qq'];
	$sql="update student_record set user_telphone='$tel',user_address='$add', user_qq='$qq' where user_name='$name' ";
	if(!mysql_query($sql,$conn)){
		die('Error: ' . mysql_error());
	}else{
		header("Location: /1/v_product.php"); 
	};

	mysql_close($conn);


?>
