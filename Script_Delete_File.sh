#!/bin/bash
echo -e "\n\n\e[1;31mSCRIPT BORRAR ARCHIVO DEL REPOSITORIO"
echo -e "\n\n\e[1;31mCUIDADO CUIDADO CUIDADO"
echo -e "\e[1;32mCreado por: Jp\e[0m"

git pull origin master
echo -e "Archivo a \e[1;31mBorrar:\e[0m"
read file
git add -u $file

echo -e "\e[1;32mListo para el Commit\e[0m"
echo -e "Ingrese un mensaje para el commit:"
read msgGit

echo -e "\n\e[1;32mCreando Commit\e[0m"
git commit -m `echo "$msgGit"`

echo -e "Enter para \e[1;32mContinuar \e[0mo Ctrl+C para \e[1;31mCancelar\e[0m"
read enter

echo -e "\e[1;32mHaciendo Push\e[0m"
git push origin master

echo -e "\n\e[1;31mFin Script :3"
