echo "Script Commit, para facilitarnos la vida :3\n"
echo "Creado por: Jp"
echo "Mensaje del Commit: "
read msgGit

git add .
git commit -m `echo "$msgGit"`
git push origin master
