void save_latex(float x[], float y[], int iorder[], int ncity){
	FILE *txt = fopen("main.tex", "w");

	if (txt == NULL)
	{
		printf("Error al cargar archivo tex\n");
		return;
	}


	// ponemos el preambulo al archivo de latex
	fprintf(txt, "\\documentclass[12pt,letterpaper]{article} \\usepackage[utf8]{inputenc} \\usepackage[spanish]{babel} \\usepackage{tikz} \\author{Jesús A . Mejía de Dios} \\begin{document}\n");
	fprintf(txt, "\\centering \\begin{tabular}{|c|} \\hline\n");
	fprintf(txt, "\\begin{tikzpicture}[scale=1.3, transform shape]\n");
	fprintf(txt, "\\tikzstyle{every node} = [circle, fill=green!30]\n");

	int i, j;

	float rad, scale = 12;
		// rad = ALEN(x[i], x[i], y[i1], y[i2]);
	
	for (i = 0; i < ncity; ++i) {
		fprintf(txt, "\\node (n%i) at ( %.5f, %.f)  {%d}; \n", i+1, scale*x[i], scale*y[i], i+1 );
	}

	for (i = 1; i <= ncity - 1; ++i) {
		fprintf(txt, "\\draw[<-, color=black] (n%d) -- (n%d);\n", iorder[i], iorder[i + 1]);
	}



	fprintf(txt, "\\end{tikzpicture}\\\\ \n ");
	fprintf(txt, "\\hline  \\end{tabular}  \n ");
	fprintf(txt, "\n\\end{document}\n");


	fclose(txt);

	system("(latexmk -C) > /dev/null && (latexmk -pdf) > /dev/null && exo-open main.pdf");	
	// system("rm main.tex");	

}


