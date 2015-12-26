<?php
	$n=trim(fgets(STDIN));
	$s=0;
	for($i=0; $i<$n; $i++)
	{
		$x=trim(fgets(STDIN));
		$s+=$x;
	}
	$ret=$n-1;
	$mod=$s%$n;
	if($mod==0)
		$ret++;
	echo $ret;
?>
