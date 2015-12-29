blabla
Deroulement du programme :

1 . Check du nombre d'arguments.


2 . Appel de fonction "read_and_check" :
	a . Ouverture du fichier en argument, gestion d'erreur (Open);
	b . Read du fichier
	c . Appel des 2 fonctions de check :
		- "check_file", qui appel "check_char_and_format" check_map(verifie si les caracteres sont OK, si la map est bien formatée dans son emsemble).
		- "check_termi", qui verifie si les termi recu sont conformes.
	d . Si une erreur apparrait dans les étapes citées ci-dessus, l'execution du programme s'arrete et envoie la raison sur la sortie d'erreur.


3 . Appel de la fonction "buffer_to_list", qui va nous decouper chaque pieces recu pour créer une liste chainée :
	a . Appel de "create_tab" qui effectus "ft_strsplit" du buffer recu en parametre.
	b . Appel "create_termi_list", qui creer une liste chainée et modifie chaque variable "piece" et "pos" pour chaque maillon a partir du tableau resultant du "ft_strsplit".
	c . Appel de "del_split_tab", qui va free le tableau resultant du "ft_strsplit";
	d . Renvoi du point "list" (début de la liste chainée).


4 . Appel de la fonction "convert_list", qui va placer chaque termi, contenu dans chaque maillons de la liste, en haut a gauche de son carée :
	a . Creation d'un pointeur temporaire pour parcourir la chaine.
	b . "put_to_top", qui va (par recursivité) placer la piece en haut de son carré.
	c . "put_to_left", qui va (par recursivité) placer la piece a l'extreme gauche de son carée.
	d . "put_to_alphabet", qui va assigner un caracteres a la piece selon son emplacement dans la liste.

5.	Appel de "solveit", qui prends la liste des pieces et pilote l'algo de résolution
	a. appel "map_size" pour calculer la taille minimal de la map
	b. génére une boucle tant que la solution n'est pas trouver qui incrémente la taille de la map a chaque echec et rappel les fonctions de résolution

6. Appel de "printit" qui se contente d'afficher la string de la solution

PATH des fonctions :

"read_file.c"		void	read_and_check(char **path);

"check_file.c"		int		check_file(char *buf, int ret);
"check_file.c"		int		check_map(int ret, int pieces);
"check_file.c"		int		check_termi(char *buf);
"check_file.c"		int		check_char_and_format(char *buf, int line, int char_nb, int pieces);

"create_list.c"		termi	*buffer_to_list(char **path, termi *list);
"create_list.c"		termi	*create_termi_list(termi *list, char *str, int pos);
"create_list.c"		char	**create_tab(char *buf, char **tab);
"create_list.c"		void	del_split_tab(char **tab, int nb_termi);

"convert_list.c"	void	convert_list(termi *list);
"convert_list.c"	char	put_to_top(termi *list, int ok);
"convert_list.c"	char	put_to_left(termi *list, int ok);
"convert_list.c"	char	*up_once(char *tmp);
"convert_list.c"	char	*left_once(char *tmp);

"convert_list2.c"	char	put_to_alphabet(termi *list, char c);

"solveit.c"			char	*solveit(termi *list);
"printit.c"			void	printit(char *solved);

"map.c"				int		map_size(termi *list);
"map.c"				char	*map_build(int map_size);
