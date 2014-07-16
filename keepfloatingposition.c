static void
keepfloatingposition(Client *c) {
	Monitor *m;
	int cmmx = c->mon->mx;
	int cmmy = c->mon->my;
	int cmmw = c->mon->mw;
	int cmmh = c->mon->mh;
	int mmx, mmy;
	if(!(cmmx <= c->x &&
			cmmx + cmmw - 1 >= c->x &&
			cmmy <= c->y &&
			cmmy + cmmh - 1 >= c->y))
		for(m = mons; m; m = m->next) {
			mmx = m->mx;
			mmy = m->my;
			if(mmx <= c->x &&
					mmx + m->mw - 1 >= c->x &&
					mmy <= c->y &&
					mmy + m->mh - 1 >= c->y) {
				c->x = c->x - mmx + cmmx;
				c->y = c->y - mmy + cmmy;
				if(c->x + c->w  + 2 * c->bw > cmmx + cmmw - 1)
					c->x -= c->x + c->w + 2 * c->bw - cmmx - cmmw;
				if(c->y + c->h + 2 * c->bw > cmmy + cmmh - 1)
					c->y -= c->y + c->h + 2 * c->bw - cmmy - cmmh;
				resizeclient(c, c->x, c->y, c->w, c->h);
				break;
			}
		}
}
