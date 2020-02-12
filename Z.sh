NombreProgramaFuente=circle
#NombreProgramaFuente=circle

rm $NombreProgramaFuente
g++ $NombreProgramaFuente.cpp -o $NombreProgramaFuente -lGL -lglut -lGLEW -lm
./$NombreProgramaFuente
