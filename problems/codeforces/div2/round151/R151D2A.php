<?php
	$n=fgets(STDIN);
	if($n<=2)
		echo '-1';
	else
		for($i=$n; $i>=1; $i-=1)
			echo $i.' ';
?>
