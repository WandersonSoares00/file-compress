
for file in ./instancias_teste/*; do
	du file
	./comp -c "$file"
	du out.dah
	./comp -d out.dah
	diff -s out "$file"
done

rm out.dah
