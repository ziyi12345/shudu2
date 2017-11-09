<?php require("index.php");?>
<div class="w3agile_contact_left">
<h1>删除学生</h1>

<?php 
 	header("Content-Type: text/html;charset=utf-8");
	require("inc.php");
	
	echo '删除成功';

	mysql_close($conn);


?>


</div>

<?php require("footer.php");?>
