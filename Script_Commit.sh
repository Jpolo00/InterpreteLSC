#!/bin/bash
echo "Script Commit, para facilitarnos la vida...\n"
echo "Creado por: Jp"

git add .
git status

echo -e "\e[1;31mListo para el Commit\e[0m"
echo -e "Ingrese un mensaje para el commit:"
read msgGit

echo -e "Enter para \e[1;32mContinuar \e[0mo Ctrl+C para \e[1;31mCancelar\e[0m"
read enter

echo -e "\e[1;32mCreando Commit\e[0m"
git commit -m `echo "$msgGit"`
echo -e "\e[1;32mHaciendo Push\e[0m"
git push origin master
echo -e "\e[1;31mFin Script :3"
