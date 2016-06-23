print("begin")

a = {1, 2};
a[1], a[2] = a[2], a[1]
print(a[1])
print(a[2])

function fact (n)
if n == 0 then
return 1
else 
return n * fact(n-1)
end
end

print("enter a number:")
a = io.read("*number")
print(fact(a))

print("end")