m=50;
n=2;
x=0:1:100;
y=exp(-(x-m).^2/(2*n^2));
subplot(2,1,1)
plot(x,y)
subplot(2,1,2)
% z=normrnd(50,2,100,1);
% plot(z)
z=0:1:100; 
d=normpdf(z,50,2); 
plot(z,d)