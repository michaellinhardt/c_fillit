red='\033[0;31m'
green='\033[0;32m'
neutre='\033[0;38m'

echo $green"Rebuild"
make re
echo $neutre"-----------"
echo $green"0 arguments :"$red
./fillit
echo $neutre"-----------"
echo $green"2 arguments :"$red
./fillit sample/invalid_four sample/char.test
echo $neutre"-----------"
echo $green"Openning error :"$red
./fillit sample/invalid_fo
echo $neutre"-----------"
echo $green"char.test :"$red
./fillit sample/char.test
echo $neutre"-----------"
echo $green"invalid_four :"$red
./fillit sample/invalid_four
echo $neutre"-----------"
echo $green"invalid_max :"$red
./fillit sample/invalid_max
echo $neutre"-----------"$red
echo $green"invalid_pieces :"$red
./fillit sample/invalid_pieces
echo $neutre"-----------"
echo $green"invalid_pieces2 :"$red
./fillit sample/invalid_pieces2
echo $neutre"-----------"
echo $green"invalid_pieces3 :"$red
./fillit sample/invalid_pieces3
echo $neutre"-----------"
echo $green"invalide_map_size :"$red
./fillit sample/invalide_map_size
echo $neutre"-----------"
echo $green"invalide_map_size2 :"$red
./fillit sample/invalide_map_size2
echo $neutre"-----------"
echo $green"valid_four :"$red
./fillit sample/valid_four
echo $neutre"-----------"$red
echo $green"valid_max :"$red
./fillit sample/valid_max
echo $neutre"-----------"$red
echo $green"valid_one :"$red
./fillit sample/valid_one
echo $neutre"-----------"$red
