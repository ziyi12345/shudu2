<?php require("index.php");?>
<div class="w3agile_contact_left">
<h1>添加同学</h1>
<form action="add_supplier.php" method="post">
名称<input type="text" name="name" value=""/>
地址<input type="text" name="address" value=""/>
电话<input type="text" name="telephone" value=""/>
</br>
QQ<input type="text" name="qq" value=""/>
简介<input type="text" name="introduce" value=""/>
微信<input type="text" name="weixin" value=""/>
email<input type="text" name="email" value=""/>
</br>
<input type="submit" value="提交">
</form>


</div>

<?php require("footer.php");?>