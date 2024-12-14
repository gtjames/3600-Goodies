import requests
import sys
import json

courseId = "320100"
school = "byui"
single = "0";

# Run the function
if len(sys.argv) > 2:
    school   = sys.argv[1]
    courseId = sys.argv[2]

# Load the JSON key file
with open('keys.json', 'r') as file:
    data = json.load(file)
    API_KEY = data[f"{school}"]
    # API_KEY = file.read()         # this is when I was just reading the file as a text file
    # API_KEY = API_KEY.rstrip("\r\n")

headers = { "Authorization": f"Bearer {API_KEY}" }

# Canvas API details
BASE_URL = f"https://{school}.instructure.com/api/v1"

def fetch_students(courseId):
    """Fetch all students in the course."""
    students = []
    url = f"{BASE_URL}/courses/{courseId}/users"
    params = {
        "enrollment_type[]": "student",
        "per_page": 100,  # Maximum allowed per page
    }

    response = requests.get(url, headers=headers, params=params)
    if response.status_code != 200:
        raise Exception(f"Failed to fetch students: {response.status_code}, {response.text}")

    # Append current page of students to the list
    students = response.json()

    return students

def fetch_assignments(courseId):
    """Fetch all assignments in the course."""
    assignments = []
    url = f"{BASE_URL}/courses/{courseId}/assignments"
    response = requests.get(url, headers=headers, params={"per_page": 100})
    if response.status_code != 200:
        raise Exception(f"Failed to fetch assignments: {response}")
    
    assignments = response.json()

    return assignments

def fetch_submission_status(courseId, assignmentId):
    """Fetch the submission status of all students for a specific assignment."""
    submissions = []
    url = f"{BASE_URL}/courses/{courseId}/assignments/{assignmentId}/submissions"
    response = requests.get(url, headers=headers, params={"per_page": 100})

    if response.status_code != 200:
        raise Exception(f"Failed to fetch submissions: {response.status_code}, {response.text}")
        
    submissions = response.json()
    return submissions

def list_unfinished_assignments(courseId):
    """List students and their unsubmitted assignments."""
    students = fetch_students(courseId)
    assignments = fetch_assignments(courseId)
    student_assignments = {student['id']: {"name": student['name'], "unsubmitted": []} for student in students}

    for assignment in assignments:
        submissions = fetch_submission_status(courseId, assignment['id'])
        for submission in submissions:
            # print(f"{submission['workflow_state']} {assignment['name']} {submission['user_id']}")
            if submission['workflow_state'] == "unsubmitted":  # Check if not submitted
                studentId = submission['user_id']
                if studentId in student_assignments:
                    student_assignments[studentId]["unsubmitted"].append(assignment['name'])
                else:
                    print(f"NEVER {studentId}")

    return student_assignments

# Example usage:
unfinished_assignments = list_unfinished_assignments(courseId)

# Display results
row = 0;
for studentId, info in unfinished_assignments.items():
    row=row+1
    print(f"Student: {row} {info['name']}")
    if info['unsubmitted']:
        print("  unSubmitted Assignments:")
        for assignment in info['unsubmitted']:
            print(f"    - {assignment}")
    else:
        print("  All assignments completed!")
    print()