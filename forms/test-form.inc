<?php
// add body text:
$page->maincontent = "<h1>$page->title</h1>" . $page->body;

/**********************************************************************
*
*
*				CREATE FORM
*
*
***********************************************************************/

// create a new form field (also field wrapper)
$form = $modules->get("InputfieldForm");
$form->action = "./";
$form->method = "post";
$form->attr("id+name",'subscribe-form');
 
// create a text input
$field = $modules->get("InputfieldText");
$field->label = "Name *";
$field->attr("id+name","name");
$field->required = 1;
$form->append($field); // append the field to the form

$field = $modules->get("InputfieldEmail");
$field->label = "Email *";
$field->attr("id+name","email");
$field->required = 1;
$form->append($field); // append the field to the form

$field = $modules->get("InputfieldSelect");
$field->label = "Select";
$field->attr("id+name","choose-one");
/*
// add options to select
$field->addOption("","Please Select");
$field->addOption("one","One");
*/
$field->addOption("","Please Select");
// create dropdown from pageArray
$parent = $pages->get("/")->children;
foreach ($parent as $child) {
	$field->addOption($child->id,$child->title);
}
$field->required = 0;
$form->append($field); // append the field to the form
 
// add a submit button
$submit = $modules->get("InputfieldSubmit");
$submit->attr("value","Subscribe");
$submit->attr("id+name","submit");
$form->append($submit);
 






/**********************************************************************
*
*
*				PROCESS FORM
*
*
***********************************************************************/


// process form
if($input->post('submit')) :

	


	// process form input
	$form->processInput($input->post);

	// if no error occured, process your form values
	if(!count($form->getErrors())):
		
		
		/**********************************************************************
		 * DATA MANIPULATION / STORAGE / ETC
		 **********************************************************************/
		foreach ($input->post as $key => $value) {
			$page->maincontent .=	$key . ' => ' . $value . '<br>';
		}
	



	else:
		// if errors exist, add errors to form
		$page->maincontent .= $form->render();
	

	endif;






else:

	// if no submit, just show form
	$page->maincontent .= $form->render();

endif;