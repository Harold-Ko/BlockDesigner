package com.twoblock.blockdesigner.popup;
//package com.twoblock.blockdesigner.perspective.popup;
//
//import java.util.Iterator;
//
//import org.eclipse.core.commands.AbstractHandler;
//import org.eclipse.core.commands.ExecutionEvent;
//import org.eclipse.core.commands.ExecutionException;
//import org.eclipse.jface.dialogs.MessageDialog;
//import org.eclipse.jface.viewers.ISelection;
//import org.eclipse.jface.viewers.IStructuredSelection;
//import org.eclipse.ui.handlers.HandlerUtil;
//
//public class ShowSelected extends AbstractHandler {
//
//	@SuppressWarnings("unchecked")
//	@Override
//	public Object execute(ExecutionEvent event) throws ExecutionException {
//		
//		MessageDialog.openInformation(null, "Hello", "World");
//		
//		ISelection selection = HandlerUtil.getActiveWorkbenchWindow(event).getActivePage().getSelection();
//		if (selection != null & selection instanceof IStructuredSelection) {
//			IStructuredSelection strucSelection = (IStructuredSelection) selection;
//			for (Iterator<Object> iterator = strucSelection.iterator(); iterator.hasNext();) {
//				Object element = iterator.next();
//				System.out.println(element.toString());
//			}
//		}
//		return null;
//	}
//
//}