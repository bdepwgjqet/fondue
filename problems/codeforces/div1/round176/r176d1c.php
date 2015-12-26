<?php
function gao($n,&$p,$sg,$st) {
	$top=-1;
	for($i=$n-1; $i>=0; $i--) {
		if($top<0||$sg[$i]||$p[$i]!=$st[$top]) {
			$st[++$top]=$p[$i];
			$p[$i]=-$p[$i];
		}
		else
			--$top;
	}
	return $top==-1;
}
$n=fgets(STDIN);
$p=explode(' ',trim(fgets(STDIN)));
$q=explode(' ',trim(fgets(STDIN)));
$sg=array();
$st=array();
for($i=0; $i<$n; $i++)
	$sg[$i]=0;
for($i=1; $i<=$q[0]; $i++)
	$sg[$q[$i]-1]=1;
if(gao($n,$p,$sg,$st)) {
	echo "YES\n";
	for($i=0; $i<$n; $i++)
		echo $p[$i].' ';
	echo "\n";
}
else
	echo "NO\n";
?>
