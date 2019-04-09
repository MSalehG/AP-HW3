insert into "User" values (default, 'a1', '09120000010', 'a1@gmail.com',
 md5('12345'),'ali8', 'alavi8', '123456798', 'http//a8', now(), now());

insert into "User" values (default, 'a2', '09120000009', 'a2@gmail.com',
 md5('12354'),'ali1', 'alavi1', '123456798', 'http//a2', now(), now());

insert into "User" values (default, 'a3', '09120000008', 'a3@gmail.com',
 md5('12435'),'ali3', 'alavi3', '123456798', 'http//a3', now(), now());

insert into "User" values (default, 'a4', '09120000001', 'a4@gmail.com',
 md5('12453'),'ali4', 'alavi4', '123456798', 'http//a4', now(), now());

insert into "User" values (default, 'a5', '09120000007', 'a5@gmail.com',
 md5('12543'),'ali5', 'alavi5', '123456798', 'http//a5', now(), now());

insert into "User" values (default, 'b1', '09351000001', 'b1@gmail.com',
 md5('12534'),'ben1', 'bush1', '123456798', 'http//b1', now(), now());

insert into "User" values (default, 'b2', '09352000002', 'b2@gmail.com',
md5('13245'),'ben2', 'bush2', '123456798', 'http//b2', now(), now());

insert into "User" values (default, 'b3', '09353000003', 'b3@gmail.com',
 md5('13254'),'ben3', 'bush3', '123456798', 'http//b3', now(), now());

insert into "User" values (default, 'b4', '09354000004', 'b4@gmail.com',
md5('14325'),'ben4', 'bush4', '123456798', 'http//b4', now(), now());

insert into "User" values (default, 'b5', '09355000005', 'b5@gmail.com',
md5('14352'),'ben5', 'bush5', '123456798', 'http//b5', now(), now());

insert into "User" values (default, 'amir.jahanshahi', '09370000001',
 'amir.jahanshahi@gmail.com',md5('14523'),'amir', 'jahanshahi',
  '123456798', 'http//amirj', now(), now());

insert into "User" values (default, 'sHDiV4RHs', '09380000001',
 'sHdiV4RHs@gmail.com', md5('14532'),'sHDi', 'V4RHs',
  '123456798', 'http//sHDi', now(), now());



insert into "Channel" values (default, 'aut_ap_2005', 'ch1',
 '', 5, now(), now());

insert into "Channel" values (default, 'aut_ap_2009', 'ch2',
 '', 1, now(), now());

insert into "Channel" values (default, 'aut_ap_2012', 'ch3',
 '', 8, now(), now());

insert into "Channel" values (default, 'aut_ap_2016', 'ch4',
 '', 1, now(), now());

insert into "Channel" values (default, 'aut_ap_2019', 'ch5',
 '', 6, now(), now());


insert into "ChannelMembership" values (9, 3, now());

insert into "ChannelMembership" values (4, 5, now());

insert into "ChannelMembership" values (5, 3, now());

insert into "ChannelMembership" values (1, 5, now());

insert into "ChannelMembership" values (8, 5, now());

insert into "ChannelMembership" values (4, 1, now());

insert into "ChannelMembership" values (6, 5, now());

insert into "ChannelMembership" values (10, 1, now());

insert into "ChannelMembership" values (7, 1, now());

insert into "ChannelMembership" values (1, 1, now());


insert into "BlockUser" values (4, 10, now());

insert into "BlockUser" values (4, 3, now());

insert into "BlockUser" values (4, 5, now() - interval '2 month');


insert into "Message" values (default, 11, 12, 'text', 
'Hey!', now(), now());

insert into "Message" values (default, 12, 11, 'text', 
'Hey back! what do you want', now(), now());

insert into "Message" values (default, 11, 12, 'text', 
'Woah! Calm down, just wanted to say hi', now(), now());

insert into "Message" values (default, 12, 11, 'text', 
'Oh! alright.', now(), now());

insert into "Message" values (default, 11, 12, 'text', 
'So why the attitude', now(), now());

insert into "Message" values (default, 12, 11, 'text', 
'Nothing just tired!', now(), now());

insert into "Message" values (default, 11, 12, 'text', 
'OH NO!', now(), now());

insert into "Message" values (default, 11, 12, 'text', 
'Hang in there!', now(), now());

insert into "Message" values (default, 11, 12, 'text', 
'You should rest!', now(), now());

insert into "Message" values (default, 12, 11, 'text', 
'Alright Imma go!', now(), now());

insert into "Message" values (default, 12, 11, 'text', 
'Bye!', now(), now());


insert into "ChannelMessage" values (default, 3, 'text',
 '1', now(), now());

insert into "ChannelMessage" values (default, 5, 'text',
 '2', now() - interval '2 month', now() - interval '2 month');

insert into "ChannelMessage" values (default, 4, 'text',
 '3', now() - interval '2 month', now() - interval '2 month');

insert into "ChannelMessage" values (default, 1, 'text',
 '4', now(), now());

insert into "ChannelMessage" values (default, 2, 'text',
 '5', now(), now());

insert into "ChannelMessage" values (default, 4, 'text',
 '6', now(), now());






