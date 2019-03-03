import sys
from math import*
def H(z,a,b):c=complex;T=lambda A,B:abs(c(*A)-c(*B));d=T(z,a);e=T(z,b);f=T(a,b);g=[d,e,f];h=max(g);g.remove(h);i=acos((sum(i*i for i in g)-(h*h))/(2*g[0]*g[-1]));_=[[z,a],[z,b],[a,b]];j,s,t=cos,sin,atan;N=[[b,a]for a,b in zip([b,a,z],[max(i,key=i.get)if i!=''else''for i in[{(g[0]+(h*j(t(l))),g[1]+(h*s(t(l)))):T(k,(g[0]+(h*j(t(l))),g[1]+(h*s(t(l))))),(g[0]-(h*j(t(l))),g[1]-(h*s(t(l)))):T(k,(g[0]-(h*j(t(l))),g[1]-(h*s(t(l)))))}if l else{(g[0]+h,g[1]):T(k,(g[0]+h,g[1])),(g[0]-h,g[1]):T(k,(g[0]-h,g[1]))}if l==0else''for g,h,l,k in zip([((a[0]+b[0])/2,(a[1]+b[1])/2)for a,b in _],[(3**0.5)*(i/2)for i in[d,e,f]],[-1/p if p else''if p==0else 0for p in[((a[1]-b[1])/(a[0]-b[0]))if a[0]-b[0]else''for a,b in _]],[b,a,z])]])if b!=''];I=N[0][0][1];J=N[0][0][0];K=N[1][0][1];G=N[1][0][0];A=(N[0][1][1]-I)/(N[0][1][0]-J);B=I-(A*J);C=(K-N[1][1][1])/(G-N[1][1][0]);D=K-(C*G);X=(D-B)/(A-C);Y=(A*X)+B;return[[X,Y],[[a,b][h==d],z][h==f]][i>2.0943]

x1, y1 = map(int, sys.stdin.readline().split())
x2, y2 = map(int, sys.stdin.readline().split())
x3, y3 = map(int, sys.stdin.readline().split())

print(' '.join(map(str, (H([x1, y1], [x2, y2], [x3, y3])))))