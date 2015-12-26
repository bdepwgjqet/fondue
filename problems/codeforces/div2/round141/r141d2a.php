<?php
	list($a,$b,$c,$d)=explode(' ',trim(fgets(STDIN)));
	$ar=array();
	$ar[$a]=1;
	$r=1;
	if(!isset($ar[$b]))
	{
		$ar[$b]=1;
		$r++;
	}
	if(!isset($ar[$c]))
	{
		$ar[$c]=1;
		$r++;
	}
	if(!isset($ar[$d]))
	{
		$r++;
		$ar[$d]=1;
	}
	$r=4-$r;
	print $r."\n";
?>
