#Build Update automation
#importing libraries
import re
#importing my own classes and packages
#globals
count = 0
build_id_int = 0
counter = 0
#function definitins
def generate_build_id(file_name):
            global counter
            global build_id_int
            replaced_text = ' '
            with open(file_name,'r+') as build_file:
                        text= build_file.readlines()
                        for line in text:
                                    counter= counter+1
                                    if(line.find('BUILD_ID')>-1):
                                                pre_processor,variable_name,variable_value=line.split(' ')  #separating name and value
                                                build_id_int= int(variable_value)
                                                build_id_int=build_id_int+1
                                                value_str= str(build_id_int)
                                                updated_build= pre_processor+' '+variable_name+' ' +value_str + '\n'
                                                replaced_text= line.replace(line,updated_build)
                                                break
                        with open(file_name,'w') as newbuild_file:
                                   # text[counter] = replaced_text
                                    newbuild_file.writelines(replaced_text)                                    
                                   
            
            return build_id_int
def update_build(file_name):
            global count 
            count = 0
            replaced_text = ' '
            with open(file_name,'r+') as build_file:
                        text= build_file.readlines()
                        for line in text:
                                    count= count+1
                                    if(line.find('BUILD_ID')>-1):
                                                pre_processor,variable_name,variable_value=line.split(' ')  #separating name and value
                                                #value_int= int(variable_value)
                                                value_int=generate_build_id("C:/DoNotDelete/BUILD_ID_LOCAL.txt")
                                                value_str= str(value_int)
                                                updated_build= pre_processor+' '+variable_name+' ' +value_str + '\n'
                                                replaced_text= line.replace(line,updated_build)
                                                break
                        with open(file_name,'w') as newbuild_file:
                                    text[count-1] = replaced_text
                                    newbuild_file.writelines(text)                                    
                                   
            
            return
#main function            
def main():
           # update_build("C:/Users/AtifM/Desktop/AutomatedTestsFiles/JenkinsTest.txt")
            update_build("VERSION_NUMBER.h")
            print(str(build_id_int))
   


if __name__== "__main__":
            main()
