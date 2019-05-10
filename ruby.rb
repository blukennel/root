######################### variables

$global_variable = 13	#globalna
@instance_variable = 14	#dostepny dla wszystkich metod w klasie
_local_variable = 15 #zwykla, moze byc bez _
Constant = 3	#const z duzej litery, ale daje tylko ostrzezenie

########################### misc

var = 123
var = var.to_s	# string casting
puts var.to_i # integer casting
var = var + " to #{var.class} teraz"	# variable output, dziala w "" tylko
var = var + var # string concatenation
puts var
puts var.class # zwraca klase obiektu
puts var.size
puts var.upcase
puts var.downcase
puts var.reverse
String.instance_methods(false) #shows class methods for this class (without false - more but useless)
puts 2.class
puts Integer.class #is class xd
str = 'a blue car'
puts str.upcase.reverse #method chaining
puts nil.object_id
puts var.object_id	# id obiektow
p 'ass' # print shortcut

######################################## classes

def foo1(n=3) #default value
	n.times do |k|	#repeat 3 times
		puts 'hello'
	end
end

def f2	# last value is returned if there is no RETURN
	2
end

class Klasa
	def initialize(arg)	#automatically private
		puts arg
	end
end

class AB
	def a
		puts 'a'	#instance method, works only with an object
	end
	def b
		puts 'b'
	end
end
class ABC < AB #inheritance
	def c
		puts 'c'
	end
end

class Know
	def self.pi 
		3.14 	# first way
	end
	class << self	#class method
		def e
			2.78	#second way
		end
	end
	def inst
		2.5
	end
end

class Getters
	def initialize
		@var = 5
		@var2 = 6
	end
	def var # getter example
		@var
	end
	attr_reader :var2 #better getter
end

class Setters
	def initialize
		@x = 4
		@y = 3
	end
	def x=(arg)	# setter example
		@x = arg
	end
	attr_reader :x, :y
	attr_writer :y	#better setter
end

class Person
	def initialize(name,number)
		@name = name
		@number = number
	end
	def to_s
		return "#{@name} - number is #{@number}" #coding string casting to a class
	end
end

class User
	attr_accessor :name,:age,:gender	# also declaring variables in a class
end

conan = Person.new('Conan',123666321)
puts conan

class Point
	@@no_of_points = 0	# static variable
    attr_accessor :x, :y #getter
    def initialize(x,y)
        @x, @y = x, y #assign multiple variables in a row
        @@no_of_points+=1
    end
    def +(other)
      Point.new(@x + other.x, @y + other.y)	# addition overloading
    end
    def to_s
        "(#{@x}, #{@y})" # string casting
    end
end

p1 = Point.new(3,4)
p2 = Point.new(2,1)
puts p1+p2

################################## ifs and loops

var = 5	# ifs
if var == 6
	puts 6
elsif var == 4
	puts 4
else
	puts 'nope'
end
puts 'hello' if 2 == 2	#short if
puts 'hi' unless 2 == 2
i=0
while i<3 do
	puts i
	i+=1
end
i=5
until i==0
	i-=1
	puts i
end

#################### iterators

puts
puts 5.times.class # class = enumerator (iterator)
# times to metoda(iterator) klasy integer
5.times {|k| puts k} # first way	# |x| -> parameters sent to block(integers in this case)
5.times do |k|	# second way
	puts k
end
5.upto(10) {|k| print(k," ")}	# upto iterator for integers, separator " " for print method

############################# structures

puts
a = [1,2,3]
puts a.class
puts a[1].class
print a
puts a[1]
b = [1, 2.3, 'ass']
print b
puts

c = Array.new
c << 12				# appending to array
c << 'auto'
c << 3.14
c.each do |item|	# 'each' iterator for arrays
	print item, " - "
end
puts

prices = {'egg' => 0.5, 'butter' => 3}	# Hashes
puts prices['egg']
puts prices.count
puts :symbol # symbol
prices = {:egg => 0.5, :butter => 3}
puts prices[:egg]
prices = {egg: 0.5, butter: 3}

words = ['hello', 'there']
puts words.map(&:upcase)	# calling function by a symbol and mapping to elements of an array

colors = {black: '#000000', white: '#FFFFFF'}
colors.each do |key, value|	
	puts "#{key}: #{value}"
end

p (0..3).class # Range
for k in 0..3	# 0..3 is inclusive
	puts k
end
for k in Range.new(0,3)	# also
	puts k
end
p (0..3).to_a	# casting to an array
print ('a'..'h').to_a
puts
p (4...6).to_a # exclusive (x...y)

################################ misc again

BEGIN {
   puts "Initializing Ruby Program" # this will run before everything else
}
END {
   puts "Goodbye" # an this at the end
}
=begin
logn comment
=end