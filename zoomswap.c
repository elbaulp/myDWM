static Client * findbefore(Client *c);

Client *
findbefore(Client *c) {
	Client *tmp;
	if(c == selmon->cl->clients)
		return NULL;
	for(tmp = selmon->cl->clients; tmp && tmp->next != c; tmp = tmp->next) ;
	return tmp;
}
