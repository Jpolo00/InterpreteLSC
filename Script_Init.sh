#!/bin/bash
echo -e "\n\n\e[1;32mScript Init, para facilitarnos la vida"
echo -e "Creado por: Jp"
echo -e "Solo ejecutarlo cuando se deba clonar el repositorio\e[0m"

echo "Repositorio a Clonar <URL HTTPS>" 
read repo
git clone $repo

echo -e "\e[1;32mRepositorio Clonado\e[0m"
echo -e "Configurando GitHub"
echo -e "<user> <email>"
read user email

git config --global --replace-all user.name "$user"
git config --global --replace-all user.email "$email"

echo -e "\e[1;31mFin Script"




