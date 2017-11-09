<?php 
 	header("Content-Type: text/html;charset=utf-8");
	require("inc.php");
?>
<?php require("index.php");?>
<div class="w3agile_contact_left">
<h3>update information</h3>
<form action="edit_post.php" method="post">
<?php
    $strsql="select user_name from student_record";

  // Ö´ÐÐsql²éÑ¯
  $result=mysql_query($strsql, $conn);

  if(!$result){
    echo('student_name<select name="user_name"><option value="0">ÎÞ</option></select>');
  }else{
  	echo 'student_name<select name="user_name">';
	  while($row = mysql_fetch_array($result))
	  {
	    echo '<option value="'.$row[0].'">'.$row[0].'</option>';
	  }
  	echo '</select>';
	echo "<input type=\"hidden\" name=\"no\" value=\"".$row['sno']."\"/>tel<input type=\"text\" name=\"tel\" value=\"".$row['telephone']."\"/>address<input type=\"text\" name=\"address\" value=\"".$row['address']."\"/>QQ<input type=\"text\"  name=\"qq\" value=\"".$row['qq']."\"/><input type=\"submit\" value=\"submit\"></form>";
			
  }
?>



?>


</form>


</div>


<?php
	mysql_close($conn);
?>


<?php require("footer.php");?>
