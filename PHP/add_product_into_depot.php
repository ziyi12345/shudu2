
<?php require("index.php");?>
<?php 
 	header("Content-Type: text/html;charset=utf-8");
	require("inc.php");
	$uname=$_POST['user_name'];
	$utel=$_POST['user_telephone'];

	$sql="select * from student_record where user_name='$uname'";
	$result=mysql_query($sql,$conn);
	if(!$result){
		echo 'no';
	}else{
		echo '<table class="table2"><tr><td>name</td><td>address</td><td>telephone</td><td>QQ</td><td>introduce</td><td>wenxin</td><td>email</td></tr>';
		  while($row = mysql_fetch_array($result))
		  {
		  	echo '<tr><td>'.$row[0].'</td><td>'.$row[1].'</td><td>'.$row[2].'</td><td>'.$row[3].'</td><td>'.$row[4].'</td><td>'.$row[5].'</td><td>'.$row[6]."</td></tr>";
		  	}
		echo "</table>";
	}
	
	mysql_close($conn);
?>
