﻿<?php 
 	header("Content-Type: text/html;charset=utf-8");
	require("inc.php");
?>
<?php require("index.php");?>
<div class="w3agile_contact_left">
<h3>查询学生</h3>
<form action="add_product_into_depot.php" method="post">
<?php
    $strsql="select user_name from student_record";

  // 执行sql查询
  $result=mysql_query($strsql, $conn);

  if(!$result){
    echo('学生姓名<select name="user_name"><option value="0">无</option></select>');
  }else{
  	echo '学生姓名<select name="user_name">';
	  while($row = mysql_fetch_array($result))
	  {
	    echo '<option value="'.$row[0].'">'.$row[0].'</option>';
	  }
  	echo '</select>';
  }
?>



?>


<input type="submit" value="提交">
</form>


</div>


<?php
	mysql_close($conn);
?>


<?php require("footer.php");?>