# Statistics

- Here's a list of all [topics](statistics/topics.md).
- Here's a list of all [questions](statistics/questions.md).

Get the all of topics and questions, and generate the Markdown files by the following instruction:

```shell
python analyzer.py -m -o [output directory]
```

Install the Python dependencies using:

```shell
python -m pip install -r requirements.txt
```

To generate the requirements.txt using the **pipreqs**.

# Solution

See all [solutions](solutions/README.md).

# Create A New Solution from Template

Following command will create a solution template folder to the solutions folder.
```
python create_solution.py [number]
```

# Auto-Update the README.md

Following command will update all of README.md files in solutions folder(except the README.md of the problem).
```
python update_readme.py
```
