void excluirRegiao(Descritor planilha,char regiao[])
{
	TpColuna *Ci,*Cf;
	TpLinha *Li,*Lf;
	
	char coli,colf;
	int lini,linf;
	
	separarRegiao(regiao,coli,colf,lini,linf);
	
	Ci = planilha.pColuna;
	while(Ci->coluna!=coli)
		Ci = Ci->prox;
	Cf=Ci;
	while(Ci->coluna!=conf)
		Cf = Cf->prox;
	Li = planilha.pLinha;
	while(Li->linha!=lini)
		Li = Li->prox;
	Lf=Li;
	while(Li->linha!=linf)
		Li = Li->prox;//18:44
}
