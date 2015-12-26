<?php
	$n=fgets(STDIN);
	$hash=array();
	for($i=0; $i<$n; $i++)
	{
		$s=trim(fgets(STDIN));
		if(isset($hash[$s]))
		{
			$hash[$s]++;
			print $s.$hash[$s]."\n";
		}
		else
		{
			$hash[$s]=0;
			print "OK\n";
		}
	}
?>
