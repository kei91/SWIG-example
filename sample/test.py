import sample

def test(a) :
	print('test')
	s = sample.sample()
	print(type(a))
	s.print_info(a);
	
def testVoid(a) :
	print('testVoid')
	s = sample.sample()
	print('sample.sample()')
	print(type(a))
	s.print_infoVoid(a);
	
def testA(a) :
	print('testA')
	s = sample.sample()
	print('sample.sample()')
	print(type(a))
	s.print_infoA(a);
	