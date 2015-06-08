<?php
	list($n,$sum)=explode(' ',fgets(STDIN));
	$dat=array();
	$l=0;
	$r=0;
	$tmp=$sum;
	for($i=0; $i<$n; $i++)
	{
		list($x,$y)=explode(' ',fgets(STDIN));
		$dat[$i]=array($x,$y);
		$l+=$x;
		$r+=$y;
		$tmp-=$x;
	}
	if($l>$sum||$r<$sum)
		print "NO\n";
	else
	{
		print "YES\n";
		for($i=0; $i<$n; $i++)
		{
			$x=$dat[$i][0];
			if($tmp>0)
			{
				$y=min($tmp,$dat[$i][1]-$x);
				$x+=$y;
				$tmp-=$y;
			}
			print $x.' ';
		}
		print "\n";
	}
?>
