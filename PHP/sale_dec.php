<?php 
 	header("Content-Type: text/html;charset=utf-8");
	require("inc.php");

	$uname=$_POST['user_name'];
	
	$sql="delete from student_record where user_name='$uname'";
	
	$result=mysql_query($sql,$conn);
	
	if(!result)
	echo 'É¾³ýÊ§°Ü';
	else		
	{echo '<script language="javascript">window.location.href="/1/v_sale.php"; </script>';

	
	mysql_close($conn);}


?>
