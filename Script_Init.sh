echo "Script Init, para facilitarnos la vida :3\n"
echo "Creado por: Jp\n"
echo "Solo ejecutarlo cuando se deba clonar el repositorio\n\n"
echo "Ruta donde desea Clonar:" 
read path
echo "Repositorio a Clonar <URL HTTPS>" 
read repo

cd $path
git clone $repo



