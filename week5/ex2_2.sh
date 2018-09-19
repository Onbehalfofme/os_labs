if test ! -f ex2_2
then
	    echo 0 > ex2_2
fi

if ln ex2_2 ex2_2.lock
then                                                                    
	for i in `seq 1 100`;
	do
		LASTNUMBER=`tail -1 ex2_2`
		LASTNUMBER=$((LASTNUMBER+1))
		echo $LASTNUMBER >> ex2_2
	done
	rm ex2_2.lock
fi
