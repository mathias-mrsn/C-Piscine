#!/bin/sh
nbr1=`echo $FT_NBR1 | sed 'y/'\''\\"?!/01234/'`
nbr2=`echo $FT_NBR2 | sed 'y/mrdoc/01234/'`
res=`echo "ibase=5;$nbr1+$nbr2" | bc`
echo "obase=13;$res" | bc | sed 'y/0123456789ABC/gtaio luSnemf/'
