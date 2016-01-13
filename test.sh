red='\033[0;31m'
green='\033[0;32m'
neutre='\033[0;38m'

echo $green"Rebuild"
make re
echo $neutre"-----------"
echo $green"0 arguments :"$red
time ./fillit
echo $neutre"-----------"
echo $green"2 arguments :"$red
time ./fillit sample/invalid_four sample/char.test
echo $neutre"-----------"
echo $green"Openning error :"$red
time ./fillit sample/invalid_fo
echo $neutre"-----------"
echo $green"char.test :"$red
time ./fillit sample/char.test
echo $neutre"-----------"
echo $green"invalid_char1 :"$red
time ./fillit sample/invalid_char1
echo $neutre"-----------"$red
echo $green"invalid_char2 :"$red
time ./fillit sample/invalid_char2
echo $neutre"-----------"$red
echo $green"invalid_char3 :"$red
time ./fillit sample/invalid_char3
echo $neutre"-----------"$red
echo $green"invalid_space1 :"$red
time ./fillit sample/invalid_space1
echo $neutre"-----------"$red
echo $green"invalid_space2 :"$red
time ./fillit sample/invalid_space2
echo $neutre"-----------"$red
echo $green"invalid_four :"$red
time ./fillit sample/invalid_four
echo $neutre"-----------"
echo $green"invalid_max :"$red
time ./fillit sample/invalid_max
echo $neutre"-----------"$red
echo $green"invalid_pieces :"$red
time ./fillit sample/invalid_pieces
echo $neutre"-----------"
echo $green"invalid_pieces2 :"$red
time ./fillit sample/invalid_pieces2
echo $neutre"-----------"
echo $green"invalid_pieces3 :"$red
time ./fillit sample/invalid_pieces3
echo $neutre"-----------"
echo $green"invalid_pieces4 :"$red
time ./fillit sample/invalid_pieces4
echo $neutre"-----------"
echo $green"invalide_map_size :"$red
time ./fillit sample/invalide_map_size
echo $neutre"-----------"
echo $green"invalide_map_size2 :"$red
time ./fillit sample/invalide_map_size2
echo $neutre"-----------"
echo $green"valid_four :"$red
time ./fillit sample/valid_four
echo $neutre"-----------"$red
echo $green"valid_max :"$red
time ./fillit sample/valid_max
echo $neutre"-----------"$red
echo $green"valid_one :"$red
time ./fillit sample/valid_one
#echo $neutre"-----------"$red
#echo $green"valid_onze :"$red
#time ./fillit sample/valid_onze
#echo $neutre"-----------"$red
#echo $green"valid_23 :"$red
#time ./fillit sample/valid_23
#echo $neutre"-----------"$red
#echo $green"valid_12 :"$red
#time ./fillit sample/valid_douze
#echo $neutre"-----------"$red



