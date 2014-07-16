static void toggleview_focus(const Arg *arg) {
	Client *c;
	toggleview(arg);
	for(c = selmon->cl->clients; !(c->tags & arg->ui) && c->next; c = c->next) ;
	if(c && c->tags & arg->ui)
		focus(c);
}
