#!/bin/bash
echo "Script Commit, para facilitarnos la vida...\n"
echo "Creado por: Jp"

git add .
git status
echo -e "\e[1;31mListo para el Commit\e[0m"
echo -e "Ingrese un mensaje para el commit:"
read msgGit
echo -e "Enter para \e[1;32mContinuar \e[0mo Ctrl+C para \e[1;31mCancelar"
read enter
git commit -m `echo "$msgGit"`
git push origin master
echo -e "\e[1;31Fin Script :3"
