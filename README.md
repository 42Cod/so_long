#### https://harm-smits.github.io/42docs/libs/minilibx

## Textures
Pour créer vos propres textures (si vous n'en trouvez pas), vous devrez convertir des fichiers PNG en fichier XPM. Vous pouvez réaliser votre propre pixel art en utilisant notamment Aseprite qui est bien plus simple d'utilisation que Photoshop. Pensez a faire des PNG transparents ayant une taille de 32 par 32 pixels ou de 64 par 64 pixels. 

Une fois les fichiers xpm créés / trouvés, une fonction de la MLX vous permettra de les afficher. Si vous avez des problèmes de "performance" sur votre fenêtre, utilisez la fonction mlx_do_sync sous MAC OS ou cherchez comment éviter cela sur Linux (*voir code*).

## Tests à effectuer
 **Ajoutez -fsanitize=address -g au Makefile**
### Parsing
* Tester avec des 0 à la places des 1 sur les murs (haut, bas, côtés).
* Tester avec des char non autorisés dans le sujet.
* Tester avec des whitespaces.
* Tester avec plusieurs joueurs.
* Tester avec aucune sortie, aucun collectible.

### Arguments 
* Tester avec des maps dont l'extension n'est pas .ber
* Tester avec des fichiers qui n'existent pas
* Tester avec un dossier qui porterait une extension .ber
* Tester sans argument 
* Tester avec trop d'arguments

![malatini](/screen.png)
