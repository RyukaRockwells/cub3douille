#!/bin/bash

> error.log

# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/01_bad_extension 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/02_BadMapPos.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/03_BadAccessRigh.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/04_tester_une_exec_avec_un_mauvais_nom_de_map.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/07_no_map.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/10_missing_texture_definition.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/11_non_existing_texture.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/12_double_texture_definition.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/20_double_color.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/21_color_bad_def_negative_number.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/22_color_bad_def_big_number.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/23_color_bad_def_too_much_number\ copy.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/24_color_bad_format.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/25_color_bad_format2.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/26_color_bad_format3.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/30_double_player_different.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/31_double_player_same.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/32_no_player.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/33_open_map.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/34_open_map_empty_line.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/35_non_valid_char_in_map_a.cub 2>> error.log
# valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/invalid_maps/36_non_valid_char_in_map_tab.cub  2>> error.log

# file1="/mnt/nfs/homes/sanauth/TC/parsecub/error_valgrind.log"
# file2="/mnt/nfs/homes/sanauth/TC/parsecub/error.log"

#nb1= wc -l $file1
#nb2= wc -l $file2
#if $nb1 == $nb2; then
#    printf 'The file "%s" is the same as "%s"\n' "$file1" "$file2"
#	printf '\e[32mOK\e[0m\n'
#else
#    printf 'The file "%s" is different from "%s"\n' "$file1" "$file2"
#	printf '\e[31mKO\e[0m\n'
#fi




####################################################





# echo -e " >>>>>>>>>>>>>>>>>>> TEST 01 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/01_bad_extension 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 02 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/02_BadMapPos.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 03 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/03_BadAccessRigh.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 04 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/04_tester_une_exec_avec_un_mauvais_nom_de_map.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 07 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/07_no_map.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 10 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/10_missing_texture_definition.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 11 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/11_non_existing_texture.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 12 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/12_double_texture_definition.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 20 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/20_double_color.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 21 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/21_color_bad_def_negative_number.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 22 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/22_color_bad_def_big_number.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 23 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/23_color_bad_def_too_much_number\ copy.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 24 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/24_color_bad_format.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 25 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/25_color_bad_format2.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 26 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/26_color_bad_format3.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 30 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/30_double_player_different.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 31 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/31_double_player_same.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 32 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/32_no_player.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 33 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/33_open_map.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 34 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/34_open_map_empty_line.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 35 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/35_non_valid_char_in_map_a.cub 2>> error.log
# echo >> error.log
# echo -e " >>>>>>>>>>>>>>>>>>> TEST 36 <<<<<<<<<<<<<<<<" >> error.log
# ./cub3D map/invalid_maps/36_non_valid_char_in_map_tab.cub  2>> error.log
# echo >> error.log

# file1="/mnt/nfs/homes/sanauth/TC/parsecub/error_copy.log"
# file2="/mnt/nfs/homes/sanauth/TC/parsecub/error.log"

# if cmp -s "$file1" "$file2"; then
#     printf 'The file "%s" is the same as "%s"\n' "$file1" "$file2"
# 	printf '\e[32mSUCCESS\e[0m\n'
# else
#     printf 'The file "%s" is different from "%s"\n' "$file1" "$file2"
# 	printf '\e[31mKO\e[0m\n'
# fi



#./cub3D map/parsing_map/unvalid/empty.cub 2>> error.log
#./cub3D map/parsing_map/unvalid/emptylines.cub 2>> error.log
# >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SEGFAULT./cub3D map/parsing_map/unvalid/emptywithspaces.cub 2>> error.log
#./cub3D map/parsing_map/unvalid/emptywithspaces.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_000.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_000.cub  2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_001.cub  2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_002.cub  2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_003.cub  2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_004.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_005.cub  2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_006.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_012.cub   2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_013.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_014.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_015.cub  2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_016.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_017.cub 2>> error.log
# #./cub3D map/parsing_map/unvalid/invalid_map_area_018.cub #file error au lieu de mauvaise position player 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_019.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_020.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_021.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_022.cub  2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_023.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_026.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_map_area_027.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_000.cub 2>> error.log
# # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SEGFAULT./cub3D map/parsing_map/unvalid/invalid_RGB_001.cub 2>> error.log
# # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SEGFAULT./cub3D map/parsing_map/unvalid/invalid_RGB_002.cub 2>> error.log
# # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SEGFAULT./cub3D map/parsing_map/unvalid/invalid_RGB_003.cub 2>> error.log
# # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SEGFAULT./cub3D map/parsing_map/unvalid/invalid_RGB_004.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_005.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_006.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_007.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_008.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_009.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_010.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_011.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_012.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_013.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_014.cub 2>> error.log
# # ./cub3D map/parsing_map/unvalid/invalid_RGB_015.cub #VALID<<<<<<<<<<<<<<<<<<<< 2>> error.log
# # ./cub3D map/parsing_map/unvalid/invalid_RGB_016.cub #VALID<<<<<<<<<<<<<<<<<<<< 2>> error.log
# # ./cub3D map/parsing_map/unvalid/invalid_RGB_017.cub #VALID<<<<<<<<<<<<<<<<<<<< 2>> error.log
# # ./cub3D map/parsing_map/unvalid/invalid_RGB_018.cub #VALID<<<<<<<<<<<<<<<<<<<< 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_019.cub #VALID alors qu'il y a 2 virgules 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_020.cub 2>> error.log
# # ./cub3D map/parsing_map/unvalid/invalid_RGB_021.cub #VALID alors qu'il y a 2 virgules 2>> error.log
# # ./cub3D map/parsing_map/unvalid/invalid_RGB_022.cub #VALID alors qu'il y a 2 virgules 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_023.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_024.cub 2>> error.log
# # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SEGFAULT ./cub3D map/parsing_map/unvalid/invalid_RGB_025.cub 2>> error.log
# # ./cub3D map/parsing_map/unvalid/invalid_RGB_026.cub # pas segfault chelou 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_027.cub  2>> error.log
# # ./cub3D map/parsing_map/unvalid/invalid_RGB_028.cub #VALID F 100,100,100, 000 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_029.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_030.cub 2>> error.log
# # ./cub3D map/parsing_map/unvalid/invalid_RGB_031.cub #VALID alors qu'il y a une virgule en trop 2>> error.log
# # ./cub3D map/parsing_map/unvalid/invalid_RGB_032.cub #VALID alors qu'il y a une virgule en trop 2>> error.log
# # ./cub3D map/parsing_map/unvalid/invalid_RGB_033.cub #VALID alors qu'il y a une virgule en trop 2>> error.log
# # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SEGFAULT ./cub3D map/parsing_map/unvalid/invalid_RGB_034.cub 2>> error.log
# # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SEGFAULT ./cub3D map/parsing_map/unvalid/invalid_RGB_035.cub 2>> error.log
# # ./cub3D map/parsing_map/unvalid/invalid_RGB_036.cub #VALID alors qu'il y a un nombre en trop C 055,000,000        4 2>> error.log
# # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SEGFAULT ./cub3D map/parsing_map/unvalid/invalid_RGB_037.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_038.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_039.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_RGB_040.cub 2>> error.log
# # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SEGFAULT./cub3D map/parsing_map/unvalid/invalid_RGB_041.cub 2>> error.log
# # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SEGFAULT./cub3D map/parsing_map/unvalid/invalid_RGB_042.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_000.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_001.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_002.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_003.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_004.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_005.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_006.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_007.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_008.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_009.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_010.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_011.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_012.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_013.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_014.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_015.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_016.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_017.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_018.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_020.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_021.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_EA_022.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_002.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_003.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_004.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_005.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_006.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_007.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_008.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_009.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_010.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_011.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_012.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_014.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_015.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_016.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_017.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_018.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_020.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_021.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_NO_022.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_000.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_001.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_002.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_003.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_004.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_005.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_006.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_007.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_008.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_009.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_010.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_011.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_012.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_013.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_014.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_015.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_016.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_017.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_018.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_020.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_021.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_SO_022.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_000.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_001.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_002.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_003.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_004.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_005.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_006.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_007.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_008.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_009.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_010.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_011.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_012.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_013.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_014.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_015.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_016.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_017.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_018.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_020.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_021.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/invalid_tex_WE_022.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/negative_rgb.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/player_err.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/point_random.cub 2>> error.log
# #./cub3D map/parsing_map/unvalid/prison.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/random.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/rgb000.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/rgb.cub 2>> error.log
# ./cub3D map/parsing_map/unvalid/unvalid_picture_path.cub 2>> error.log




valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/empty.cub 2>> error.log
valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/emptylines.cub 2>> error.log
valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/emptywithspaces.cub 2>> error.log #SEGFAULT
valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/emptywithspaces.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_000.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_001.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_002.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_003.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_004.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_005.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_006.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_012.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_013.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_014.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_015.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_016.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_017.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_018.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_019.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_020.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_021.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_022.cub 
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_023.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_026.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_map_area_027.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_000.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_001.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_002.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_003.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_004.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_005.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_006.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_007.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_008.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_009.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_010.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_011.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_012.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_013.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_014.cub
##valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_015.cub
##valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_016.cub
##valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_017.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_018.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_019.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_020.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_021.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_022.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_023.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_024.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_025.cub
##valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_026.cub
##valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_027.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_028.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_029.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_030.cub
##valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_031.cub
##valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_032.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_033.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_034.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_035.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_036.cub
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_037.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_038.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_039.cub
#valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_040.cub
##valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_041.cub
##valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_RGB_042.cub

# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_000.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_001.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_002.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_003.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_004.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_005.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_006.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_007.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_008.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_009.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_010.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_011.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_012.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_013.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_014.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_015.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_016.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_017.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_018.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_020.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_021.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_EA_022.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_002.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_003.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_004.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_005.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_006.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_007.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_008.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_009.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_010.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_011.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_012.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_014.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_015.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_016.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_017.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_018.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_020.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_021.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_NO_022.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_000.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_001.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_002.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_003.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_004.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_005.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_006.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_007.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_008.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_009.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_010.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_011.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_012.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_013.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_014.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_015.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_016.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_017.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_018.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_020.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_021.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_SO_022.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_000.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_001.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_002.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_003.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_004.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_005.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_006.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_007.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_008.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_009.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_010.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_011.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_012.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_013.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_014.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_015.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_016.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_017.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_018.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_020.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_021.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/invalid_tex_WE_022.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/negative_rgb.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/player_err.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/point_random.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/prison.cub 2>> error.log #Good mais rien à faire l
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/random.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/rgb000.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/rgb.cub 2>> error.log
# valgrind -s --leak-check=full --show-leak-kinds=all ./cub3D map/parsing_map/unvalid/unvalid_picture_path.cub 2>> error.log
#
